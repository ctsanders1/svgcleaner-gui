/****************************************************************************
**
** SVG Cleaner could help you to clean up your SVG files
** from unnecessary data.
** Copyright (C) 2012-2018 Evgeniy Reizner
**
** This program is free software; you can redistribute it and/or modify
** it under the terms of the GNU General Public License as published by
** the Free Software Foundation; either version 2 of the License, or
** (at your option) any later version.
**
** This program is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.
**
** You should have received a copy of the GNU General Public License along
** with this program; if not, write to the Free Software Foundation, Inc.,
** 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
**
****************************************************************************/

#include "attributespage.h"
#include "ui_attributespage.h"

using namespace CleanerKey;

AttributesPage::AttributesPage(QWidget *parent)
    : BasePreferencesPage(parent)
    , ui(new Ui::AttributesPage)
{
    ui->setupUi(this);

    ui->layTransform->setContentsMargins(leftMargin(), 0, 0, 0);

    addOptWidgets({
        { ui->chBoxRmVersion, Attributes::RemoveVersion },
        { ui->chBoxRmNonSvg, Attributes::RemoveNonSvgAttributes },
        { ui->chBoxRmUnrefIds, Attributes::RemoveUnrefIds },
        { ui->chBoxTrimIds, Attributes::TrimIds },
        { ui->chBoxRmTextAttrs, Attributes::RemoveTextAttributes },
        { ui->chBoxRmCoord, Attributes::RemoveUnusedCoordinates },
        { ui->chBoxRmDefaultAttrs, Attributes::RemoveDefaultAttributes },
        { ui->chBoxXmlnsXlink, Attributes::RemoveXmlnsXlinkAttribute },
        { ui->chBoxRmNeedlessAttrs, Attributes::RemoveNeedlessAttributes },
        { ui->chBoxRemoveGradientAttributes, Attributes::RemoveGradientAttributes },
        { ui->cmbBoxJoinStyleAttributes, Attributes::JoinStyleAttributes },
        { ui->chBoxApplyTransformToGradients, Attributes::ApplyTransformToGradients },
        { ui->chBoxApplyTransformToShapes, Attributes::ApplyTransformToShapes },
        { ui->chBoxRemoveUnresolvedClasses, Attributes::RemoveUnresolvedClasses },
    });

    ui->cmbBoxJoinStyleAttributes->addItem(tr("No"), "no");
    ui->cmbBoxJoinStyleAttributes->addItem(tr("Some"), "some");
    ui->cmbBoxJoinStyleAttributes->addItem(tr("All"), "all");

    setupToolTips();
}

AttributesPage::~AttributesPage()
{
    delete ui;
}
