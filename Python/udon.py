import threading
import queue

udon_executed = False
soup_executed = False

# うどんを茹でる関数
def boil_udon(q):
    try:
        global udon_executed
        print("  ◆スレッド:", threading.currentThread().getName())
        print('  うどんを茹でます。')
        if False:  # この条件をTrueにするとエラーをテストできます。
            raise RuntimeError('うどんがくっついてしまいました')
        # Trueになると下記2行が実行されない
        print('  うどんが茹であがりました。')
        q.put('うどん完成')  # 成功時のみキューに結果を追加
        udon_executed = True
    except Exception as e:
        print(f"エラー発生: {e}")
        q.put(f"エラー発生: {e}")

def make_tuyu(q):
    try:
        global soup_executed
        print("  ◆スレッド:", threading.currentThread().getName())
        print('  出汁を取ります。')
        if False:  # この条件をTrueにするとエラーをテストできます。
            raise RuntimeError('だしの材料が足りません！')
        # Trueになると下記2行が実行されない
        print('  つゆが出来上がりました。')
        q.put('つゆ完成')  # 成功時のみキューに結果を追加
        soup_executed = True
    except Exception as e:
        print(f"エラー発生: {e}")

# メイン
if __name__ == "__main__":
    print("◆スレッド:", threading.currentThread().getName())
    print('うどんを作ります。')

    # タスクの結果を格納するキュー
    task_queue = queue.Queue()

    # スレッドを作る
    subthread1 = threading.Thread(target=boil_udon, args=(task_queue,))
    subthread2 = threading.Thread(target=make_tuyu, args=(task_queue,))

    # スレッドの処理を開始
    subthread1.start()
    subthread2.start()

    # スレッドの処理を待つ
    subthread1.join()
    subthread2.join()

    # キューから結果を取得して処理
    while not task_queue.empty():
        task_result = task_queue.get()
        print(f'  メインスレッドが受け取りました: {task_result}')

    # if udon_executed == True and soup_executed == True:
    if udon_executed and soup_executed:
        print('盛り付けます。')
        print('うどんができました。')
        print('召し上がれ!!!!')
    elif not udon_executed and soup_executed:
        print("麺が上手く茹でられませんでした")
    elif udon_executed and not soup_executed:
        print("スープに失敗しました")
    else:
        print("全然だめでした")
