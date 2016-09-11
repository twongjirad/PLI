//
// Example C++ routine to run instantiate your sample class
//
#include <TROOT.h>
#include <TDirectory.h>
#include "PyAnalzyer/PyAnalyzer.h"
#include "DataFormat/storage_manager.h"
#include "BasicTool/FhiclLite/ConfigManager.h"
#include <iostream>

int main(int argc, char** argv){

  // create storage manager
  larlite::storage_manager* mystore = new larlite::storage_manager( larlite::storage_manager::kREAD );
  std::string input = "~/working/larbys/data/mc_sample/v05/larlite/mcc7_bnb_cosmic_detsim_to_larlite_v00_p00/larlite_opdigit_0000.root";
  mystore->add_in_filename( input );
  mystore->open();
  mystore->next_event();

  // load configuration
  fcllite::ConfigManager cfg("MainConfig"); // head parameter set name
  cfg.AddCfgFile( "cfg.fcl" );
  
  // crea
  larlite::PyAnalyzer my_clss_object;
  my_clss_object.configure( cfg.SubConfig( "PyAnalyzer" ) );
  my_clss_object.analyze( mystore );


  return 0;
}
