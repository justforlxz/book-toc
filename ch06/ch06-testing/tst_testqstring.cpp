#include <QLineEdit>

#include <QtTest>

class TestQLineEdit : public QObject
{
    Q_OBJECT
private slots:
    void testToUpper();
    void testToLower();
    void testToLower_data();
};

void TestQLineEdit::testToUpper()
{
    // 测试全小写的情况
    QString str = "hello";
    QVERIFY(str.toUpper() == "HELLO");

    // 测试全大写的情况
    str = "HELLO";
    QVERIFY(str.toUpper() == "HELLO");

    // 测试混合大小写的情况
    str = "Hello";
    QVERIFY(str.toUpper() == "HELLO");
}

void TestQLineEdit::testToLower()
{
    // 获取input列测试数据
    QFETCH(QString, input);
    // 获取expected列测试数据
    QFETCH(QString, expected);

    // 断言
    QCOMPARE(input.toLower(), expected);
}

void TestQLineEdit::testToLower_data()
{
    // 添加input列
    QTest::addColumn<QString>("input");
    // 添加expected列
    QTest::addColumn<QString>("expected");

    // 添加全小写的测试数据行，数据需要按照上面数据列的顺序进行添加
    QTest::newRow("all lower") << "hello" << "hello";
    // 添加混合大小写的测试数据行
    QTest::newRow("mixed")     << "Hello" << "hello";
    // 添加全大写的测试数据行
    QTest::newRow("all upper") << "HELLO" << "hello";
}

// 生成main函数
QTEST_MAIN(TestQLineEdit)

// 包含moc生成文件
#include "tst_TestQLineEdit.moc"
