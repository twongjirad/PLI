

print "the store: ",event_storage_manager
storage_manager = event_storage_manager.get_store("storage_manager")
print "Storage_manager: ",storage_manager

runid    = storage_manager.run_id()
subrunid = storage_manager.subrun_id()
eventid  = storage_manager.event_id()

print "current event: ",runid,subrunid,eventid
