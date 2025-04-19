import sysv_ipc
key = sysv_ipc.ftok("msgqfile", 65)
queue = sysv_ipc.MessageQueue(key, sysv_ipc.IPC_CREAT | 0o666)
message = "Hello from the background sender!"
queue.send(message)
print(f"Message sent: {message}")
