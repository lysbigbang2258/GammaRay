/*
  paintbuffermodel.h

  This file is part of GammaRay, the Qt application inspection and
  manipulation tool.

  Copyright (C) 2012-2017 Klarälvdalens Datakonsult AB, a KDAB Group company, info@kdab.com
  Author: Volker Krause <volker.krause@kdab.com>

  Licensees holding valid commercial KDAB GammaRay licenses may use this file in
  accordance with GammaRay Commercial License Agreement provided with the Software.

  Contact info@kdab.com if any conditions of this licensing are not clear to you.

  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 2 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef GAMMARAY_WIDGETINSPECTOR_PAINTBUFFERMODEL_H
#define GAMMARAY_WIDGETINSPECTOR_PAINTBUFFERMODEL_H

#include <config-gammaray.h>

#ifdef HAVE_PRIVATE_QT_HEADERS
#include <QAbstractItemModel>

#include <private/qpaintbuffer_p.h>

QT_BEGIN_NAMESPACE
class QPaintBuffer;
struct QPaintBufferCommand;
QT_END_NAMESPACE

namespace GammaRay {
/**
 * Model that shows commands stored in a QPaintBuffer.
 */
class PaintBufferModel : public QAbstractItemModel
{
    Q_OBJECT
public:
    explicit PaintBufferModel(QObject *parent = nullptr);

    void setPaintBuffer(const QPaintBuffer &buffer);
    QPaintBuffer buffer() const;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QModelIndex index(int row, int column, const QModelIndex & parent) const override;
    QModelIndex parent(const QModelIndex & child) const override;

    QVariant headerData(int section, Qt::Orientation orientation,
                        int role = Qt::DisplayRole) const override;

private:
    QVariant argumentAt(const QPaintBufferCommand &cmd, int index) const;
    QString argumentDisplayString(const QPaintBufferCommand &cmd) const;
    QVariant argumentDecoration(const QPaintBufferCommand &cmd) const;

    QPaintBuffer m_buffer;
    QPaintBufferPrivate *m_privateBuffer;
};
}

#endif

#endif // GAMMARAY_PAINTBUFFERMODEL_H
