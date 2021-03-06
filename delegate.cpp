/****************************************************************************
**
** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** You may use this file under the terms of the BSD license as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor
**     the names of its contributors may be used to endorse or promote
**     products derived from this software without specific prior written
**     permission.
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
** $QT_END_LICENSE$
**
****************************************************************************/

/*
    delegate.cpp

    A delegate that allows the user to change integer values from the model
    using a spin box widget.
*/

#include <QtGui>

#include "delegate.h"


ItemDelegate::ItemDelegate(QObject *parent)
    : QItemDelegate(parent)
{
}

//返回一个编辑控件，用来编辑指定项的数据
QWidget *ItemDelegate::createEditor(QWidget *parent,
    const QStyleOptionViewItem & option ,
    const QModelIndex & index ) const
{
    //返回该控件
    if (index.column() == 2) {
        QComboBox *editor = new QComboBox(parent);
        editor->addItems(QStringList() << "male" << "famel");
        return editor;
    }
    return QItemDelegate::createEditor(parent,option,index);
}
//将Model中数据赋值到控件上
void ItemDelegate::setEditorData(QWidget *editor,
                                    const QModelIndex &index) const
{
    if (index.column() != 2) {
        QItemDelegate::setEditorData(editor,index);
        return;
    }
    //返回该索引的模型，继而返回该模型中此索引的编辑角色数据
    int value = index.model()->data(index, Qt::UserRole).toInt();
    //给控件赋值
    QComboBox *comBox = static_cast<QComboBox*>(editor);
    if (value == 1) {
        comBox->setCurrentIndex(0);
    } else if (value == 0) {
        comBox->setCurrentIndex(1);
    }
}
//设定模型数据，根据指定项中对应编辑控件的数据
void ItemDelegate::setModelData(QWidget *editor, QAbstractItemModel *model,
                                   const QModelIndex &index) const
{
    if (index.column() != 2) {
        QItemDelegate::setModelData(editor,model,index);
        return;
    }

    QComboBox *comBox = static_cast<QComboBox*>(editor);
    int value = comBox->currentIndex();
    //设置模型的数据
    model->setData(index, value, Qt::UserRole);
}
//更新编辑框几何形状
void ItemDelegate::updateEditorGeometry(QWidget *editor,
    const QStyleOptionViewItem &option, const QModelIndex &/* index */) const
{
    //根据option,设置编辑框位置
    editor->setGeometry(option.rect);
}


sexItemDelegate::sexItemDelegate(QObject *parent):
    QItemDelegate(parent)
{

}

void sexItemDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    if (index.column() == 2) {
        int sexID =  index.model()->data(index, Qt::DisplayRole).toInt();
        QString sexStr;
        if (sexID == 0) {
            sexStr = "nv";
        } else if (sexID == 1) {
            sexStr = "nan";
        } else {
            sexStr = "unknow";
        }

        //获取项风格设置
        QStyleOptionViewItem myOption = option;
        myOption.displayAlignment = Qt::AlignRight | Qt::AlignVCenter;
        //绘制文本
        drawDisplay(painter, myOption, myOption.rect, sexStr);
    } else{
        //否则默认
        QItemDelegate::paint(painter, option, index);
    }
}
