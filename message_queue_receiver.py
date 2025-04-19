import sysv_ipc
key = sysv_ipc.ftok("msgqfile", 65)
queue = sysv_ipc.MessageQueue(key, sysv_ipc.IPC_CREAT | 0o666)
message, _ = queue.receive()
print(f"Message received: {message.decode()}")
queue.remove()
