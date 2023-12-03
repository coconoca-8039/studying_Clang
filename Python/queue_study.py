import threading
import queue

# 基本的には先入先出のことをキューという
# レジに並んでいるイメージ
# 後入先出のことをスタックという
# 積み重なった書類のイメージ

# うどんを茹でる関数
def boil_udon(q):
    print("  ◆スレッド:", threading.currentThread().getName())
    print('  うどんを茹でます。')
    print('  うどんが茹であがりました。')
    q.put('うどん完成')  # キューに結果を追加

def make_tuyu(q):
    print("  ◆スレッド:", threading.currentThread().getName())
    print('  出汁を取ります。')
    print('  つゆが出来上がりました。')
    q.put('つゆ完成')  # キューに結果を追加

# メイン
if __name__ == "__main__":
    print("◆スレッド:", threading.currentThread().getName())
    print('うどんを作ります。')

    # タスクの結果を格納するキュー
    task_queue = queue.Queue()  

    # スレッドを作る
    # キューを使う時は、args=(~,)と記述する
    subthread1 = threading.Thread(target=boil_udon, args=(task_queue,))
    subthread2 = threading.Thread(target=make_tuyu, args=(task_queue,))

    # スレッドの処理を開始
    # Pythonのスレッドは、タスクが完了すれば自動的に終了する
    subthread1.start()
    subthread2.start()

    # スレッドの処理を待つ
    subthread1.join()
    subthread2.join()

    # キューから結果を取得して処理
     # task_queue.emptyはキューが空かどうか確認するメソッド
    while not task_queue.empty(): 
        # task_queue.get()はキューを先頭から取り出すメソッド
        task_result = task_queue.get()
        print(f'  メインスレッドが受け取りました: {task_result}')

    print('盛り付けます。')
    print('うどんができました。')
    print('召し上がれ!!!!')