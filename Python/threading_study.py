import threading

# 参考URL
# https://qiita.com/tchnkmr/items/b05f321fa315bbce4f77
# https://zenn.dev/nekoallergy/articles/py-advance-threading-01

# うどんを茹でる関数
def boil_udon():
    print("  ◆スレッド:", threading.currentThread().getName())
    print('  うどんを茹でます。')
    print('  うどんが茹であがりました。')

def make_tuyu():
    print("  ◆スレッド:", threading.currentThread().getName())
    print('  出汁を取ります。')
    print('  つゆが出来上がりました。')

# メイン
if __name__ == "__main__":
    print("◆スレッド:", threading.currentThread().getName())
    print('うどんを作ります。')

    # スレッドを作る
    subthread1 = threading.Thread(target=boil_udon)
    subthread2 = threading.Thread(target=make_tuyu)

    # スレッドの処理を開始
    # Mainthreadと並行してsubthread1と2が実行される
    subthread1.start()
    subthread2.start()

    # スレッドの処理を待つ
    # .join()を実行することで、subthread1と2の処理が終わるまでMainThreadが待つ
    subthread1.join()
    subthread2.join()

    print('盛り付けます。')
    print('うどんができました。')
    print('召し上がれ!!!!')

# ◆スレッド: MainThread
#うどんを作ります。
 #◆スレッド: Thread-1
  #うどんを茹でます。
  #うどんが茹であがりました。
  #◆スレッド: Thread-2
  #出汁を取ります。
  #つゆが出来上がりました。
#盛り付けます。
#うどんができました。
#召し上がれ!!!!
