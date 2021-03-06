/*
    Copyright (C) 2013 by Maxim Biro <nurupo.contributions@gmail.com>
    
    This file is part of Tox Qt GUI.
    
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.
    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
    
    See the COPYING file for more details.
*/

#include "friendrequestdialog.hpp"

#include <QVBoxLayout>
#include <QDialogButtonBox>
#include <QLabel>
#include <QLineEdit>
#include <QPlainTextEdit>
#include <QPushButton>

FriendRequestDialog::FriendRequestDialog(QWidget *parent, const QString &userId, const QString &message) :
    QDialog(parent)
{
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
    setWindowTitle("Friend request");

    QLabel *friendsLabel = new QLabel("Someone wants to make friends with you.", this);
    QLabel *userIdLabel = new QLabel("User ID:", this);
    QLineEdit *userIdEdit = new QLineEdit(userId, this);
    userIdEdit->setReadOnly(true);
    QLabel *messageLabel = new QLabel("Friend request message:", this);
    QPlainTextEdit *messageEdit = new QPlainTextEdit(message, this);
    messageEdit->setReadOnly(true);


    QDialogButtonBox *buttonBox = new QDialogButtonBox(Qt::Horizontal, this);

    buttonBox->addButton("Accept", QDialogButtonBox::AcceptRole);
    buttonBox->addButton("Reject", QDialogButtonBox::RejectRole);

    connect(buttonBox, &QDialogButtonBox::accepted, this, &FriendRequestDialog::accept);
    connect(buttonBox, &QDialogButtonBox::rejected, this, &FriendRequestDialog::reject);

    QVBoxLayout *layout = new QVBoxLayout(this);

    layout->addWidget(friendsLabel);
    layout->addSpacing(12);
    layout->addWidget(userIdLabel);
    layout->addWidget(userIdEdit);
    layout->addWidget(messageLabel);
    layout->addWidget(messageEdit);
    layout->addWidget(buttonBox);

    resize(300, 200);
}
