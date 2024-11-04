#include <iostream>
#include <string>
using namespace std;

class Book {
public:
    Book(string book_title, string book_author, int book_pages)
        : title(book_title), author(book_author), pages(book_pages) {}

    // 基本情報を表示するprintInfo
    virtual void printInfo() {  // virtualを使うことでオーバーライド可能にする
        cout << "タイトル: " << title << endl;
        cout << "著者: " << author << endl;
    }

    // オーバーロード：詳細情報を表示するprintInfo
    void printInfo(bool detailed) {
        printInfo();  // 基本情報を表示
        if (detailed) {
            cout << "ページ数: " << pages << endl;
        }
    }

protected:
    string title;
    string author;
    int pages;
};

// Bookを継承したEBookクラス
class EBook : public Book {
public:
    EBook(string book_title, string book_author, int book_pages, double file_size)
        : Book(book_title, book_author, book_pages), fileSize(file_size) {}

    // オーバーライド：EBook特有のファイルサイズ情報も表示
    void printInfo() override {
        Book::printInfo();  // 基本情報は基底クラスに任せる
        cout << "ファイルサイズ: " << fileSize << "MB" << endl;
    }

    // オーバーロード：詳細情報を表示するprintInfo
    void printInfo(bool detailed) {
        printInfo();  // オーバーライドしたprintInfoを呼び出し
        if (detailed) {
            cout << "ページ数: " << pages << endl;
        }
    }

private:
    double fileSize;  // EBook特有のメンバ変数
};

int main() {
    Book paperBook("Pride and Prejudice", "Jane Austen", 432);
    EBook digitalBook("1984", "George Orwell", 328, 1.5);

    cout << "紙の本の基本情報:" << endl;
    paperBook.printInfo();

    cout << "\n電子書籍の基本情報（オーバーライド）:" << endl;
    digitalBook.printInfo();

    cout << "\n紙の本の詳細情報（オーバーロード）:" << endl;
    paperBook.printInfo(true);

    cout << "\n電子書籍の詳細情報（オーバーロード）:" << endl;
    digitalBook.printInfo(true);

    return 0;
}
