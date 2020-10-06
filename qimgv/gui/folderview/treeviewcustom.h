#ifndef TREEVIEWCUSTOM_H
#define TREEVIEWCUSTOM_H

#include <QTreeView>
#include <QDragEnterEvent>
#include <QMimeData>
#include <QScrollBar>
#include <QDebug>
#include "settings.h"

class TreeViewCustom : public QTreeView
{
    Q_OBJECT
public:
    TreeViewCustom(QWidget *parent = nullptr);
    virtual QSize minimumSizeHint() const override;

signals:
    void droppedIn(QList<QString>, QModelIndex);

protected:
    void dragEnterEvent(QDragEnterEvent *event) override;
    void dropEvent(QDropEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;

    void enterEvent(QEvent *event);
    void leaveEvent(QEvent *event);
    void showEvent(QShowEvent *event);
private slots:
    void updateScrollbarStyle();
private:
    QScrollBar overlayScrollbar;

    const int SCROLLBAR_WIDTH = 12;
};

#endif // TREEVIEWCUSTOM_H
