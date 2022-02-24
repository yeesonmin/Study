#include "MDI.h"
#include <QMenu>
#include <QAction>
#include <QMenuBar>
#include <QToolBar>
#include <QDockWidget>
#include <QListWidget>
#include <QStatusBar>
#include <QDebug>

MDI::MDI(QWidget *parent)
    : QMainWindow(parent)
{
    QMenu* fileMenu;
    QAction* newAct;
    QAction* openAct;

    newAct = new QAction(QIcon(":/MDI/images/new.png"), tr("&New"), this);
    newAct->setShortcuts(QKeySequence::New);
    newAct->setStatusTip(tr("Create a new file"));
    connect(newAct, SIGNAL(triggered()), this, SLOT(newFile()));

    openAct = new QAction(QIcon(":/MDI/images/open.png"), tr("&Open"), this);
    openAct->setShortcuts(QKeySequence::Open);
    openAct->setStatusTip(tr("Open an existing file"));
    connect(openAct, SIGNAL(triggered()), this, SLOT(open()));

    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(newAct);
    fileMenu->addAction(openAct);

    QToolBar* fileToolBar;
    fileToolBar = addToolBar(tr("File"));
    fileToolBar->addAction(newAct);
    fileToolBar->addAction(openAct);

    QDockWidget* dock = new QDockWidget(tr("Target"), this);
    dock->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);

    QListWidget* customerList = new QListWidget(dock);
    customerList->addItems(QStringList()
        << "One"
        << "Two"
        << "Three"
        << "Four"
        << "Five");

    dock->setWidget(customerList);
    addDockWidget(Qt::RightDockWidgetArea, dock);

    setCentralWidget(new MDIMainWindow());


    statusBar()->showMessage(tr("Ready"));
}

MDI::~MDI()
{
}

void MDI::open()
{
    qDebug() << Q_FUNC_INFO;
}

void MDI::newFile()
{
    qDebug() << Q_FUNC_INFO;
}

