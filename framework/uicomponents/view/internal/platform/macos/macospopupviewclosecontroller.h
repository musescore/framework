/*
 * SPDX-License-Identifier: GPL-3.0-only
 * MuseScore-CLA-applies
 *
 * MuseScore
 * Music Composition & Notation
 *
 * Copyright (C) 2021 MuseScore BVBA and others
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 3 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#ifndef MUSE_UICOMPONENTS_MACOSPOPUPVIEWCLOSECONTROLLER_H
#define MUSE_UICOMPONENTS_MACOSPOPUPVIEWCLOSECONTROLLER_H

#include <QAbstractNativeEventFilter>

#include "../../popupviewclosecontroller.h"

namespace muse::uicomponents {
class MacOSPopupViewCloseController : public PopupViewCloseController, public QAbstractNativeEventFilter
{
    Q_OBJECT

public:
    explicit MacOSPopupViewCloseController(QObject* parent = nullptr);
    ~MacOSPopupViewCloseController() override = default;

private:
#ifdef MU_QT5_COMPAT
    bool nativeEventFilter(const QByteArray& eventType, void* message, long* result) override;
#else
    bool nativeEventFilter(const QByteArray& eventType, void* message, qintptr* result) override;
#endif

    void doUpdateEventFilters() override;

    void initWindowMinimizedObserver();
};
}

#endif // MUSE_UICOMPONENTS_MACOSPOPUPVIEWCLOSECONTROLLER_H
