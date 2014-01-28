/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * Evgeniy Alekseev wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return
 * ----------------------------------------------------------------------------
 */
/**
 * @file clear_items.cpp
 * Source code of mathmech
 * @author Evgeniy Alekseev (arcanis)
 * @copyright Beerware
 * @bug No known bugs
 */

#include "clear_items.h"

#include "mainwindow.h"
#include "ui_mainwindow.h"

Clear_items::Clear_items(MainWindow *wid) :
  parent(wid)
{

}

void Clear_items::clear_trj()
{
  parent->ui->trj_lineEdit_workDir->clear();
  parent->ui->trj_lineEdit_input->clear();
  parent->ui->trj_comboBox_type->setCurrentIndex(0);
  parent->ui->trj_spinBox_steps->setValue(1);
  parent->ui->trj_lineEdit_atoms->clear();
  parent->ui->trj_lineEdit_output->clear();
  parent->ui->trj_spinBox_totalTypes->setValue(1024);
  parent->ui->trj_checkBox_log->setCheckState(Qt::Checked);
  parent->ui->trj_lineEdit_log->clear();
}

void Clear_items::clear_statgen()
{
  parent->ui->statgen_lineEdit_workDir->clear();
  parent->ui->statgen_lineEdit_input->clear();
  parent->ui->statgen_spinBox_stepsFirst->setValue(1);
  parent->ui->statgen_spinBox_stepsLast->setValue(1);
  parent->ui->statgen_doubleSpinBox_cellX->setValue(0.1);
  parent->ui->statgen_doubleSpinBox_cellY->setValue(0.1);
  parent->ui->statgen_doubleSpinBox_cellZ->setValue(0.1);
  parent->ui->statgen_spinBox_atoms0->setValue(0);
  parent->ui->statgen_checkBox_atoms1->setCheckState(Qt::Unchecked);
  parent->ui->statgen_spinBox_atoms1->setValue(0);
  parent->ui->statgen_spinBox_atoms2->setValue(0);
  parent->ui->statgen_spinBox_atoms3->setValue(0);
  parent->ui->statgen_doubleSpinBox_int->setValue(0.0);
  parent->ui->statgen_listWidget_int->clear();
  parent->ui->statgen_lineEdit_output->clear();
  parent->ui->statgen_checkBox_depth->setCheckState(Qt::Checked);
  parent->ui->statgen_spinBox_depth->setValue(10);
  parent->ui->statgen_checkBox_log->setCheckState(Qt::Checked);
  parent->ui->statgen_lineEdit_log->clear();
  parent->ui->statgen_checkBox_anal->setCheckState(Qt::Unchecked);
  parent->ui->statgen_doubleSpinBox_anal->setValue(0.05);
  parent->ui->statgen_checkBox_graph->setCheckState(Qt::Checked);
}

void Clear_items::clear_envir()
{
  parent->ui->envir_lineEdit_workDir->clear();
  parent->ui->envir_lineEdit_input->clear();
  parent->ui->envir_doubleSpinBox_cellX->setValue(0.1);
  parent->ui->envir_doubleSpinBox_cellY->setValue(0.1);
  parent->ui->envir_doubleSpinBox_cellZ->setValue(0.1);
  parent->ui->envir_lineEdit_output->clear();
  parent->ui->envir_spinBox_molecule->setValue(1);
  parent->ui->envir_doubleSpinBox_radius->setValue(0.0);
  parent->ui->envir_checkBox_log->setCheckState(Qt::Checked);
  parent->ui->envir_lineEdit_log->clear();
}

void Clear_items::clear_radf()
{
  parent->ui->radf_lineEdit_workDir->clear();
  parent->ui->radf_lineEdit_input->clear();
  parent->ui->radf_spinBox_stepsFirst->setValue(1);
  parent->ui->radf_spinBox_stepsLast->setValue(1);
  parent->ui->radf_doubleSpinBox_cellX->setValue(0.1);
  parent->ui->radf_doubleSpinBox_cellY->setValue(0.1);
  parent->ui->radf_doubleSpinBox_cellZ->setValue(0.1);
  parent->ui->radf_lineEdit_output->clear();
  parent->ui->radf_comboBox_atom->setCurrentIndex(0);
  parent->ui->radf_spinBox_atoms0->setValue(0);
  parent->ui->radf_spinBox_atoms1->setValue(0);
  parent->ui->radf_spinBox_atoms2->setValue(0);
  parent->ui->radf_spinBox_atoms3->setValue(0);
  parent->ui->radf_spinBox_atoms4->setValue(0);
  parent->ui->radf_spinBox_atoms5->setValue(0);
  parent->ui->radf_doubleSpinBox_radMin->setValue(2.0);
  parent->ui->radf_doubleSpinBox_radMax->setValue(15.0);
  parent->ui->radf_doubleSpinBox_radStep->setValue(0.2);
  parent->ui->radf_checkBox_ang->setCheckState(Qt::Unchecked);
  parent->ui->radf_doubleSpinBox_angMin->setValue(0.0);
  parent->ui->radf_doubleSpinBox_angMax->setValue(90.0);
  parent->ui->radf_doubleSpinBox_angStep->setValue(15.0);
  parent->ui->radf_checkBox_matrix->setCheckState(Qt::Unchecked);
  parent->ui->radf_checkBox_log->setCheckState(Qt::Checked);
  parent->ui->radf_lineEdit_log->clear();
  parent->ui->radf_checkBox_graph->setCheckState(Qt::Checked);
}

void Clear_items::clear_pdb()
{
  parent->ui->pdb_comboBox_mode->setCurrentIndex(0);
  parent->ui->pdb_lineEdit_workDir->clear();
  parent->ui->pdb_lineEdit_input->clear();
  parent->ui->pdb_lineEdit_agl->clear();
  parent->ui->pdb_doubleSpinBox_cellX->setValue(0.1);
  parent->ui->pdb_doubleSpinBox_cellY->setValue(0.1);
  parent->ui->pdb_doubleSpinBox_cellZ->setValue(0.1);
  parent->ui->pdb_lineEdit_output->clear();
  parent->ui->pdb_checkBox_log->setCheckState(Qt::Checked);
  parent->ui->pdb_lineEdit_log->clear();
}
