#ifndef CONTRAST_H
#define CONTRAST_H

#include <QWidget>
#include <QVector>
#include <QCloseEvent>
namespace Ui {
class Contrast;
}

class Contrast : public QWidget
{
    Q_OBJECT

public:
    explicit Contrast(QWidget *parent = nullptr);
    void closeEvent(QCloseEvent *event);
    void pieChart(QVector<int> vec);
    void barChart(QVector<int> vec);
    ~Contrast();

private:
    Ui::Contrast *ui;

signals:
    void emitExit();
private slots:
    void get_init(QVector<int>);
};

#endif // CONTRAST_H
