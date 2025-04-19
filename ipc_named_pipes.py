import os
fifo_path = "/tmp/my_fifo"
message = b"Hello from sender!"
os.mkfifo(fifo_path, 0o666)
fd = os.open(fifo_path, os.O_RDWR)
if fd < 0:
raise Exception("Opening FIFO failed")
os.write(fd, message)
buffer = os.read(fd, 20)
print("Received:", buffer.decode())
os.close(fd)
os.unlink(fifo_path)
