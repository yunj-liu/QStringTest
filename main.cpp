#include <QCoreApplication>
#include <iostream>
#include <QTimer>
//using namespace std;
using std::cout, std::endl;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString str = "Hello";
    cout << "abc123" << endl;
    cout << str.toStdString().data() << endl;
    cout << "str.size():" << str.size() << endl;
    //qDebug() << str;  // will display the double quotation

    // if not add QChar() will error in "cannot convert from 'int' to 'QChar'"
    static const QChar data[4] = {QChar(0x0055), QChar(0x006e), QChar(0x10e3), QChar(0x03a3)};
    QString s1(data, 4);
    cout << "s1:" << s1.toStdString().data() << endl;
    //static const QChar a1 = 0x0055; // static const QChar a1 = QChar(0x0055);
    //cout << a1.toLatin1() << endl;

    QString s2;
    s2.resize(4);
    s2[0] = QChar('U');
    s2[1] = QChar('n');
    s2[2] = QChar(0x10e3);
    s2[3] = QChar(0x03a3);
    cout << "s2:" << s2.toStdString().data() << endl;

    // For read-only access, an alternative syntax is to use the at() function
    // The at() function can be faster than operator[](), because it never causes a deep copy to occur.
    for (qsizetype i=0; i<s2.size(); ++i) {
        if(s2.at(i)>=QChar('a') && s2.at(i) <= QChar('q'))
            qDebug() << "Found character in range [a-q]";
    }

    //first()
    QString x = "Pineapple";
    QString y = x.first(4);      // y == "Pine"
    qDebug() << y;
    //cout << y.toStdString().data() << endl;

    //last()
    QString x2 = "Pineapple";
    QString y2 = x2.last(5);      // y == "apple"
    qDebug() << y2;

    //sliced()
    QString x3 = "Nine pineapples";
    QString y3 = x3.sliced(5, 4);            // y == "pine"
    QString z3 = x3.sliced(5);               // z == "pineapples"
    qDebug() << "y3:" << y3;
    qDebug() << "z3:" << z3;

    //endswith()
    QString str4 = "Bananas";
    qDebug() << str4.endsWith("anas");         // returns true
    qDebug() << str4.endsWith("pple");         // returns false
    qDebug() << str4.endsWith('s');

    //startsWith
    QString str5 = "Bananas";
    qDebug() << str5.startsWith("Ban");     // returns true
    qDebug() << str5.startsWith("Car");     // returns false

    //chop
    QString str6("LOGOUT\r\n");
    str6.chop(2);
    // str6 == "LOGOUT"
    qDebug() << "str6:" << str6;

    //chopped
    QString str7("LOGOUT\r\n");
    QString str8 = str7.chopped(2);
    qDebug() << "str7:" << str7;
    qDebug() << "str8:" << str8;

    //truncate
    QString str9 = "Vladivostok";
    str9.truncate(4);
    // str9 == "Vlad"
    qDebug() << "str9:" << str9;

    //resize
    QString s3 = "Hello world";
    s3.resize(5);
    qDebug() << s3;  // s3=="Hello"
    s3.resize(8);
    qDebug() << s3;
    qDebug() << s3.size();
    qDebug() << s3.sliced(5, 3);
    QString s4 = s3.sliced(4, 3);
    qDebug() << s4;




    //Add this, otherwise the Qt console program will not end automatically
    QTimer t;
    t.connect(&t, SIGNAL(timeout()), &a, SLOT(quit()));
    t.start(10);  //10millisecond
    return a.exec();
}
