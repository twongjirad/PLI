# PyLard Interface: PyAnalyzer

The intention of this analyzer is to allow one to develop a new algorithm, mid-analyzer chain, in a python environment.  
The unit passes the current storage_manager instance to a python environment where the user's python script is run.  
Any new data objects can be passed into that storage_manager instance and, therefore, to any downstream analyzers.

