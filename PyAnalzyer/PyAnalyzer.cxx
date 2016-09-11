#ifndef LARLITE_PYANALYZER_CXX
#define LARLITE_PYANALYZER_CXX

#include "PyAnalyzer.h"
#include "TPython.h"
#include "TObjString.h"
#include "DataFormat/storage_store.h"

namespace larlite {

  void PyAnalyzer::configure( const fcllite::PSet& pset ) {
    fPyFilePath   = pset.get<std::string>("PyFilePath");
    fStoreVarName = pset.get<std::string>("StorageVariableName","event_storage_store");
  }

  bool PyAnalyzer::initialize() {

    //
    // This function is called in the beggining of event loop
    // Do all variable initialization you wish to do here.
    // If you have a histogram to fill in the event loop, for example,
    // here is a good place to create one on the heap (i.e. "new TH1D"). 
    //


    return true;
  }
  
  bool PyAnalyzer::analyze(storage_manager* storage) {
  
    //
    // Do your event-by-event analysis here. This function is called for 
    // each event in the loop. You have "storage" pointer which contains 
    // event-wise data. To see what is available, check the "Manual.pdf":
    //
    // http://microboone-docdb.fnal.gov:8080/cgi-bin/ShowDocument?docid=3183
    // 
    // Or you can refer to Base/DataFormatConstants.hh for available data type
    // enum values. Here is one example of getting PMT waveform collection.
    //
    // event_fifo* my_pmtfifo_v = (event_fifo*)(storage->get_data(DATA::PMFIFO));
    //
    // if( event_fifo )
    //
    //   std::cout << "Event ID: " << my_pmtfifo_v->event_id() << std::endl;
    //

    // create a storage_store instance and give it the storage_manager instance
    larlite::storage_store* thestore = new larlite::storage_store();
    thestore->add_store( "storage_manager", storage );

    // bind the storage_manager instance to the python environment
    TPython::Bind( thestore, fStoreVarName.c_str() );

    // run user macro
    TPython::LoadMacro( fPyFilePath.c_str() );
    // I need exception handling here

    // delete the storage instance
    delete thestore;
  
    return true;
  }

  bool PyAnalyzer::finalize() {

    // This function is called at the end of event loop.
    // Do all variable finalization you wish to do here.
    // If you need, you can store your ROOT class instance in the output
    // file. You have an access to the output file through "_fout" pointer.
    //
    // Say you made a histogram pointer h1 to store. You can do this:
    //
    // if(_fout) { _fout->cd(); h1->Write(); }
    //
    // else 
    //   print(MSG::ERROR,__FUNCTION__,"Did not find an output file pointer!!! File not opened?");
    //
  
    return true;
  }

}
#endif
