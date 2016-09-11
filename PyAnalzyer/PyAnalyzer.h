/**
 * \file PyAnalyzer.h
 *
 * \ingroup PyAnalzyer
 * 
 * \brief Class def header for a class PyAnalyzer
 *
 * @author twongjirad
 */

/** \addtogroup PyAnalzyer

    @{*/

#ifndef LARLITE_PYANALYZER_H
#define LARLITE_PYANALYZER_H

#include "Analysis/ana_base.h"
#include "BasicTool/FhiclLite/PSet.h"

class TObjString;

namespace larlite {
  /**
     \class PyAnalyzer
     User custom analysis class made by SHELL_USER_NAME
   */
  class PyAnalyzer : public ana_base{
  
  public:

    /// Default constructor
    PyAnalyzer(){ _name="PyAnalyzer"; _fout=0;}

    /// Default destructor
    virtual ~PyAnalyzer(){}

    /** IMPLEMENT in PyAnalyzer.cc!
        Initialization method to be called before the analysis event loop.
    */ 
    virtual bool initialize();

    /** IMPLEMENT in PyAnalyzer.cc! 
        Analyze a data event-by-event  
    */
    virtual bool analyze(storage_manager* storage);

    /** IMPLEMENT in PyAnalyzer.cc! 
        Finalize method to be called after all events processed.
    */
    virtual bool finalize();

    void configure( const fcllite::PSet& pset );

  protected:

    std::string fStoreVarName; //< Name given to python variable that storage_store instance will be bound to
    std::string fPyFilePath;   //< Path to python file that analyzer will run
    
  };
}
#endif

//**************************************************************************
// 
// For Analysis framework documentation, read Manual.pdf here:
//
// http://microboone-docdb.fnal.gov:8080/cgi-bin/ShowDocument?docid=3183
//
//**************************************************************************

/** @} */ // end of doxygen group 
