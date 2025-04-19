import sysv_ipc
import os
import time
import warnings # Import the warnings module
# Ignore warnings from sysv_ipc library
with warnings.catch_warnings():
warnings.simplefilter("ignore")
key = sysv_ipc.ftok("shmfile", 65)
shm = sysv_ipc.SharedMemory(key, sysv_ipc.IPC_CREAT, 0o666, 1024)
shm.write("Hello from shared memory!")
time.sleep(20) # Wait for 20 seconds before the terminated
shm.detach()
shm.remove()
