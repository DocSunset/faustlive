//
//  JA_audioSettings.cpp
//  
//
//  Created by Sarah Denoux on 15/07/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#include "JA_audioSettings.h"
#include "FLSettings.h"

JA_audioSettings::JA_audioSettings(QGroupBox* parent) : AudioSettings(parent){

    QFormLayout* layout = new QFormLayout;
    
    fAutoConnectBox = new QCheckBox(parent);
    
    layout->addRow(new QLabel(tr("Auto-Connection")), fAutoConnectBox);
    
    parent->setLayout(layout);
    
    setVisualSettings();

}

JA_audioSettings::~JA_audioSettings(){}

void JA_audioSettings::setVisualSettings(){

    bool checked = FLSettings::_Instance()->value("General/Audio/Jack/AutoConnect", true).toBool();
    
    if(checked)
        fAutoConnectBox->setCheckState(Qt::Checked);
    else
        fAutoConnectBox->setCheckState(Qt::Unchecked);

}
void JA_audioSettings::storeVisualSettings(){

    FLSettings::_Instance()->setValue("General/Audio/Jack/AutoConnect", get_AutoConnect());
}

bool JA_audioSettings::isEqual(AudioSettings*){
    
//    if(FLSettings::_Instance()->value("General/Audio/Jack/AutoConnect", true).toBool() == get_AutoConnect())

//    Not really the right thing to say with the actual system but JA settings don't influence audio updates so it's directly stored
    storeVisualSettings();
        return true;
//    else
//        return false;
}

bool JA_audioSettings::get_AutoConnect(){
    
    if(fAutoConnectBox->checkState() == Qt::Checked)
        return true;
    else
        return false;
}

QString JA_audioSettings::get_ArchiName(){
    return "Jack";
}
