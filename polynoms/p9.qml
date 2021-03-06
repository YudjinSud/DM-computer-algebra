import QtQuick 2.3
import QtQuick.Controls 1.2

import io.qt.examples.BackendIOWrapper 1.0

ApplicationWindow {
    id: p9
    property int algo : 9
    width: 400; height: 400
    color: "#00557f"
    title: qsTr("Частное")
    visible: true

    BackendIOWrapper {
        id : backend
    }

    Text {
        id: desN1
        x: 18
        y: 11
        width: 370
        height: 146
        color: "#d5f476"
        text: qsTr("Частное от деления
многочлена на многочлен
при делении с остатком")
        font.pixelSize: 20
    }

    Button {
        id: button
        x: 171
        y: 219
        text: qsTr("Вычислить")
        onClicked: {
            console.log(algo);
            textArea.text = backend.calculatePoly(backend.input1, backend.input2, 0, "(1)/(1)",  algo)
        }
    }

    TextField {
        id: textField
        x: 35
        y: 145
        width: 324
        height: 25
        placeholderText: qsTr("           Первый полином")
        text: backend.input1
        onTextChanged: backend.input1 = text

    }

    TextField {
        id: textField1
        x: 35
        y: 188
        width: 324
        height: 25
        placeholderText: qsTr("           Второй полином")
        text: backend.input2
        onTextChanged: backend.input2 = text
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
