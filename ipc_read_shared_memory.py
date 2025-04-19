import sysv_ipc
import warnings
SHM_SIZE = 1024
# Ignore warnings from sysv_ipc library
with warnings.catch_warnings():
warnings.simplefilter("ignore")
key = sysv_ipc.ftok("shmfile", 65)
# Attach to the shared memory segment
shm = sysv_ipc.SharedMemory(key)
# Read the message from the shared memory segment
message = shm.read().decode('utf-8').rstrip('\0')
print(f"Message from shared memory: {message}")
# Detach from the shared memory segment
shm.detach()
# Remove the shared memory segment
shm.remove()
