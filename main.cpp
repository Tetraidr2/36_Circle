#include <QApplication>
#include <QPushButton>
#include <QPixmap>
#include <QPainter>
#include <QPaintEvent>
#include <filesystem>
#include <iostream>
#include <QVBoxLayout>
#include <QSlider>

class ImageCircle: public QPushButton{

public:
    ImageCircle() = default;
    ImageCircle(QWidget *parent);
    void paintEvent(QPaintEvent *e) override;
    QSize sizeHint() const override;
    QSize minimumSizeHint() const override;

public slots:
    void setDown(int);
private:
    QPixmap mCurrentPixmap;
    QPixmap greenPixmap;
    QPixmap yellowPixmap;
    QPixmap redPixmap;
};

ImageCircle::ImageCircle(QWidget *parent) {
    setParent(parent);
    setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
    auto path = std::filesystem::current_path().parent_path();
    std::string s1 = path.string() + "\\png\\krugY.png";
    yellowPixmap = QPixmap(s1.c_str());
    s1=path.string() + "\\png\\krugG.png";
    greenPixmap = QPixmap(s1.c_str());
    s1=path.string() + "\\png\\krugR.png";
    redPixmap = QPixmap(s1.c_str());
    mCurrentPixmap = yellowPixmap;
    setGeometry(mCurrentPixmap.rect());
    connect(this,&QPushButton::clicked,this, &ImageCircle::setDown);

}
void ImageCircle::paintEvent(QPaintEvent *e) {
    QPainter p(this);
    p.drawPixmap(e->rect(),mCurrentPixmap);
}
QSize ImageCircle::sizeHint() const {
    return QSize(200,200);
}
QSize ImageCircle::minimumSizeHint() const {
    return sizeHint();
}


void ImageCircle::setDown(int p) {
    if(p<34) mCurrentPixmap = greenPixmap;
    else if(p>66) mCurrentPixmap=redPixmap;
    else mCurrentPixmap = yellowPixmap;
    update();
}



int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    QWidget *window = new QWidget(nullptr);
    ImageCircle *circle =new ImageCircle(window);
    circle->setFixedSize(300,300);
    auto *slider = new QSlider(Qt::Horizontal);
    slider->setMinimum(0);
    slider->setMaximum(100);
    slider->setValue(50);
    circle->move(500,500);
    QObject::connect(slider, &QSlider::valueChanged, circle, &ImageCircle::setDown);
    auto *layout = new QVBoxLayout(window);
    layout->addWidget(circle);
    layout->addWidget(slider);
    window->resize(300,300);
    window->move(500,500);
    window->show();
    return a.exec();
}
