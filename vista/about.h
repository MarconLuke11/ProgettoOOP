#ifndef ABOUT_H
#define ABOUT_H

#include <QDialog>
#include <QLabel>
#include <QLayout>

class About: public QDialog
{
    Q_OBJECT
public:
    explicit About(QWidget *parent = nullptr);

};

#endif // ABOUT_H
