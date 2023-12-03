import subprocess

# 'echo'コマンドで"Hello World"を出力するためのコマンド
cmd = ["echo", "Hello World"]

# コマンドを実行し、その出力を受け取る
process = subprocess.Popen(cmd, stdout=subprocess.PIPE)

# 出力を取得してデコード
# 標準出力のデータをoutputに、標準エラーのデータは無視（_）している
output, _ = process.communicate()
# decodeはbyte型をstr型に変換している
# stripは文字列先頭や末尾の空白(スペース、タブ、改行)を削除している
output = output.decode().strip()

##############################
process = subprocess.Popen(["echo", "Hello World"], stdout=subprocess.PIPE)

# 標準出力からデータを読み取る
for line in process.stdout:
    print(line.decode().strip())

print(output)  # "Hello World"を出力

#process.communicate()の利点
#ブロッキング動作: process.communicate()は、
# プロセスが完了するまで実行をブロック（待機）します。
# つまり、プロセスが終了し、すべての出力が得られるまでPythonスクリプトは次の行に進みません。
#標準出力と標準エラーの両方を取得: 
# このメソッドは標準出力と標準エラー出力の両方を同時に取得することができます。
#デッドロックを避ける: 大量の出力を扱う場合、
# process.communicate()は内部的にバッファを適切に管理し、デッドロックを防ぎます。

#process.stdoutの利用
#process.stdoutは、プロセスの標準出力に直接アクセスするためのファイルオブジェクトです。
#この方法では、プロセスの出力をリアルタイムで読み取ることができますが、
# プロセスが大量のデータを出力する場合、バッファがいっぱいになるとデッドロックが発生する可能性があります。
#また、process.stdoutを使用する場合、標準エラー出力を同時に取得することはできません。