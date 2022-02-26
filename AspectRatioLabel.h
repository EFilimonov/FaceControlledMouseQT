#pragma once
// Thanks to https://stackoverflow.com/users/265521/timmmm
#include <QLabel>

class AspectRatioLabel : public QLabel
{
public:
    explicit AspectRatioLabel(QWidget* parent = nullptr, Qt::WindowFlags f = Qt::WindowFlags());
    ~AspectRatioLabel();

public slots:
    void setPixmap(const QPixmap& pm);

protected:
    void resizeEvent(QResizeEvent* event) override;

private:
    void updateMargins();

    int pixmapWidth = 0;
    int pixmapHeight = 0;
};
