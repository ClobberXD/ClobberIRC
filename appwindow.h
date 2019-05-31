#pragma once

#include "ui_appwindow.h"

class AppWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit AppWindow(QWidget *parent = nullptr);

private:
	Ui::AppWindow ui;
};
