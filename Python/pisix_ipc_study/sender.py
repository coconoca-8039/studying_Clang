import posix_ipc
import sys
import time

# メッセージキューの名前
mq_name = "/test_mq"

# メッセージキューの作成
mq = posix_ipc.MessageQueue(mq_name, posix_ipc.O_CREAT)

try:
    # メッセージの送信
    mq.send("Hello from sender!".encode())
    print("Message sent.")
except posix_ipc.BusyError:
    print("Message queue is full.")
except Exception as e:
    print(f"An error occurred: {e}")

# メッセージキューを閉じる
mq.close()