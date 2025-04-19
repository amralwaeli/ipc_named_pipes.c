import posix_ipc
import os
import time
sem_name = "/my_semaphore"
try:
semaphore = posix_ipc.Semaphore(sem_name, posix_ipc.O_CREAT | posix_ipc.O_EXCL, 0o666, 0)
except posix_ipc.ExistentialError:
raise Exception("Creating semaphore failed")
pid = os.fork()
if pid < 0:
raise Exception("Fork failed")
elif pid == 0:
print("Child waiting for semaphore")
semaphore.acquire()
print("Child acquired semaphore")
# Critical section starts
time.sleep(5)
# Critical section ends
semaphore.release()
semaphore.close() # Close the semaphore in the child process
else:
time.sleep(1)
print("Parent releasing semaphore")
semaphore.release()
os.waitpid(pid, 0)
semaphore.close() # Close the semaphore in the parent process
# Unlink the semaphore after closing it
posix_ipc.unlink_semaphore(sem_name)
