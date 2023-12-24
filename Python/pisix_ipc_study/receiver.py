import posix_ipc
import sys

# メッセージキューの名前
mq_name = "/test_mq"

# メッセージキューを開く
mq = posix_ipc.MessageQueue(mq_name)

try:
    # メッセージの受信
    message, _ = mq.receive()
    print("Received message:", message.decode())
except posix_ipc.ExistentialError:
    print("The message queue does not exist.")
except Exception as e:
    print(f"An error occurred: {e}")

# メッセージキューを閉じる
mq.close()