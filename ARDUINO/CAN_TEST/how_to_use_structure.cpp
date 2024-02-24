typedef struct{

    uint8_t byte1; // 受信データの1バイト目を格納する 
    uint8_t byte2; // 受信データの2バイト目を格納する
    uint8_t byte3; // 受信データの3バイト目を格納する
    uint8_t byte4; // 受信データの4バイト目を格納する
    uint8_t byte5; // 受信データの5バイト目を格納する
    uint8_t byte6; // 受信データの6バイト目を格納する
    uint8_t byte7; // 受信データの7バイト目を格納する
    uint8_t byte8; // 受信データの8バイト目を格納する
    
}stCanRcvData;


// memcpy関数を使うと受信した8バイトのデータを構造体にコピーすることが出来ます。
// 例えば、1バイト目の値によって処理を分けたいときは以下のソースコードのように記述します。

void funcA(uint8_t *pData)　// pDataには8バイトのデータが入っているとする
{
    // 変数定義
    stCanRcvData rcvData;

    // 受信したデータをコピーする
    memcpy(&rcvData, pData, 8); // 受信した8バイトのデータを構造体にコピーする

    // 受信したデータの1バイト目によって処理を分岐させる
    switch(rcvData.byte1){

    // 0x00のとき
    case 0x00:

        // 処理を書く
        break;
        
    // 0x01のとき
    case 0x01:

        // 処理を書く
        break;
        
    // 0x02のとき
    case 0x02:

        // 処理を書く
        break;
        
    // 上記以外のとき
    default:

        // 処理を書く
        break;

    }
    
}

// 1バイト目の値によって処理を分けるだけなら構造体を定義しなくてもよく、下記のコードでも上記と同様の処理が実現できます。


void funcA(uint8_t *pData)
{
    // 受信したデータの1バイト目によって処理を分岐させる
    switch(pData[1]){            // pData[1]で1バイト目にアクセスできる
    
    // 0x00のとき
    case 0x00:

        // 処理を書く
        break;
        
    // 0x01のとき
    case 0x01:

        // 処理を書く
        break;
        
    // 0x02のとき
    case 0x02:

        // 処理を書く
        break;
        
    // 上記以外のとき
    default:

        // 処理を書く
        break;

    }
    
}