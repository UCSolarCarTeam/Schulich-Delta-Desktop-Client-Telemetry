#include <QVBoxLayout>
#include <QTabWidget>
#include <QWidget>
#include "OverlordWidget.h"

OverlordWidget::OverlordWidget(QList<QWidget*> viewWindows,
							   QWidget *parent)
: QWidget(parent)
, viewWindows_(viewWindows)
, state_("Single")
// , settingsWindow_(settings)
// , escWindow_(escWindow)
{
	QVBoxLayout* overlordLayout = new QVBoxLayout;
	QTabWidget* tabBar = new QTabWidget();
	overlordLayout->setContentsMargins(0, 0, 0, 0);
	foreach(QWidget* window, viewWindows_){
		tabBar->addTab(window, window->windowTitle());
	}
	tabBar->setStyleSheet("QTabBar::tab { height: 50px;\n width: 175px; \nbackground: rgb(180, 180, 180);\nfont-size: 20px; }");
	overlordLayout->addWidget(tabBar);
	setLayout(overlordLayout);
    showFullScreen();
}

OverlordWidget::~OverlordWidget()
{
}

QString OverlordWidget::changeState()
{
	if(state_ .compare("Single") == 0){
		state_ = "Multi";
	}
	else if(state_.compare("Multi") == 0){
		state_ = "Single";
	}
	return state_;
}

QString OverlordWidget::getState()
{
	return state_;
}

// void OverlordWidget::showSettings()
// {
// }