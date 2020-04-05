import QtQuick 2.3
import QtQuick.Controls 1.2

import io.qt.examples.BackendIOWrapper 1.0

ApplicationWindow {
    id: p5
    property int algo : 5
    width: 400; height: 400
    color: "#00557f"
    title: qsTr("Старший коэффициент многочлена")
    visible: true

    BackendIOWrapper {
        id : backend
    }

    Text {
        id: desN1
        x: 15
        y: 13
        width: 370
        height: 146
        color: "#d5f476"
        text: qsTr("Старший коэффициент
многочлена")
        font.pixelSize: 20
    }

    Button {
        id: button
        x: 171
        y: 219
        text: qsTr("Вычислить")
        onClicked: {
            console.log(algo);
            textArea.text = backend.calculatePoly(backend.input1, backend.input1, 0, "(1)/(1)",  algo)
        }
    }


    TextField {
        id: textField
        x: 35
        y: 145
        width: 324
        height: 25
        placeholderText: qsTr("            Полином")
        text: backend.input1
        onTextChanged: backend.input1 = text

    }


    TextArea {
        id: textArea
        x: 35
        y: 250
        width: 324
        height: 106
        readOnly: true
    }
}
