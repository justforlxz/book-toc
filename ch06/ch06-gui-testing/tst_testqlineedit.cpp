#include <QLineEdit>
#include <QtTest>

class TestQString : public QObject
{
    Q_OBJECT
private slots:
    void testInput();
    void testInputAndDelete();
    void testInputAndDelete_data();
};

void TestQString::testInput()
{
    QLineEdit lineEdit;

    // 模拟键盘输入
    QTest::keyClicks(&lineEdit, "hello world");

    // 断言
    QCOMPARE(lineEdit.text(), QString("hello world"));
}

void TestQString::testInputAndDelete()
{
    // 获取events列测试数据
    QFETCH(QTestEventList, events);
    // 获取expected列测试数据
    QFETCH(QString, expected);

    QLineEdit lineEdit;

    // 模拟将测试事件数据发送到lineEdit对象
    events.simulate(&lineEdit);

    // 断言
    QCOMPARE(lineEdit.text(), expected);
}

void TestQString::testInputAndDelete_data()
{
    // 添加events列
    QTest::addColumn<QTestEventList>("events");
    // 添加expected列
    QTest::addColumn<QString>("expected");

    // 构造测试事件数据
    QTestEventList list1;
    list1.addKeyClick('a');

    // 添加测试数据行
    QTest::newRow("char") << list1 << "a";

    // 构造测试事件数据
    QTestEventList list2;
    list2.addKeyClick('a');
    list2.addKeyClick(Qt::Key_Backspace);

    // 添加测试数据行
    QTest::newRow("there and back again") << list2 << "";
}

// 生成main函数
QTEST_MAIN(TestQString)

// 包含moc生成文件
#include "tst_testqlineedit.moc"
