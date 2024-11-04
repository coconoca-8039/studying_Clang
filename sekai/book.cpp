#include <iostream>
#include <string>
using namespace std;
#define NEWLINE std::cout << std::endl

class Book{
    public:
        Book(string book_title, string book_author, int book_pages);
        ~Book();
        void nextPage();
        void prevPage();
        int getCurrentPage();
        string getTitle();
        string getAuthor();

        // 静的メンバ関数
        static int getCount();

    private:
        string title;       // タイトル
        string author;      // 著者
        int pages;          // 総ページ数
        int currentPage;    // 現在読んでいるページ

        // 静的メンバ変数
        static int count;
};

// 静的メンバ変数の初期化（定義）
int Book::count = 0;

Book::Book(string book_title, string book_author, int book_pages) : title(book_title), author(book_author) 
            ,pages(book_pages), currentPage(0){
    cout << "Bookクラスのインスタンスの生成" << endl;
    count++;  // インスタンス生成ごとにカウントを増やす
    NEWLINE;
}

Book::~Book(){
    count--;  // インスタンスが破棄されるとカウントを減らす
    NEWLINE;
    cout << "Bookクラスのインスタンスの消去" << endl;
}

void Book::nextPage(){
    if (currentPage < pages) {  // 最終ページを超えないようにする
        currentPage++;
    }
}

void Book::prevPage(){
    if (currentPage > 1) {  // 1ページ目より前に戻らないようにする
        currentPage--;
    }
}
int Book::getCurrentPage(){
    return currentPage;
}

string Book::getTitle(){
    return title;
}

string Book::getAuthor(){
    return author;
}

// 静的メンバ関数の定義
int Book::getCount() {
    return count;
}

int main(){
    // スタック領域 ローカル変数や関数の引数、速く確保・解放されるがメモリ量が限られている 
    Book myBook("The Great Gatsby", "F. Scott Fitzgerald", 180);
    cout << "読んでいる本: " << myBook.getTitle() << endl;
    cout << "読んでいる本: " << myBook.getAuthor() << endl;
    cout << "現在のページ: " << myBook.getCurrentPage() << endl;
    myBook.nextPage();  // 次のページに進む
    cout << "現在のページ: " << myBook.getCurrentPage() << endl;
    myBook.prevPage();  // 前のページに戻る
    cout << "現在のページ: " << myBook.getCurrentPage() << endl;

    // ヒープ領域 動的にメモリを確保・解放できる。newとdeleteで管理するが、管理がやや複雑
    // newとdeleteを使用することでヒープ領域で管理することができる
    Book* novel = new Book("To Kill a Mockingbird", "Harper Lee", 281);
    cout << "読んでいる本: " << novel->getTitle() << endl;
    cout << "著者: " << novel->getAuthor() << endl;
    cout << "現在のページ: " << novel->getCurrentPage() << endl;
    novel->nextPage();  // 次のページに進む
    cout << "現在のページ: " << novel->getCurrentPage() << endl;
    novel->prevPage();  // 前のページに戻る
    cout << "現在のページ: " << novel->getCurrentPage() << endl;
    delete novel;

    // 静的領域 グローバル変数や静的変数が使う領域で、プログラム終了まで保持される

    Book* novel1 = new Book("Pride and Prejudice", "Jane Austen", 432);
    Book* novel2 = new Book("Moby Dick", "Herman Melville", 635);
    cout << "現在の本の数: " << Book::getCount() << endl;
    delete novel1;
    cout << "本を1冊削除後の数: " << Book::getCount() << endl;
    delete novel2;
    cout << "すべての本を削除後の数: " << Book::getCount() << endl;

    return 0;   
    
}