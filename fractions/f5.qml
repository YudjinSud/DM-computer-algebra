import QtQuick 2.3
import QtQuick.Controls 1.2

import io.qt.examples.BackendIOWrapper 1.0

ApplicationWindow {
    id: f5
    property int algo : 5
    width: 400; height: 400
    color: "#00557f"
    title: qsTr("Сложение дробей")
    visible: true

    BackendIOWrapper {
        id : backend
    }

    Text {
        id: desN1
        x: 15
        y: 13
        width: 370
        height: 139
        color: "#d5f476"
        text: qsTr("Сложение дробей")
        font.pixelSize: 20
    }

    Button {
        id: button
        x: 171
        y: 219
        text: qsTr("Мне повезет!")
        onClicked: {
            console.log(algo);
            textArea.text = backend.calculateFraction(backend.input1, backend.input2, 0,  algo)
        }
    }

    TextField {
        id: textField
        x: 15
        y: 188
        width: 181
        height: 25
        placeholderText: qsTr("     Первая      Дробь")

        text: backend.input1
        onTextChanged: backend.input1 = text

    }

    TextField {
        id: textField3
        x: 202
        y: 189
        width: 181
        height: 25
        placeholderText: qsTr("     Вторая      Дробь")

        text: backend.input2
        onTextChanged: backend.input2 = text
    }

    TextArea {
        id: textArea
        x: 80
        y: 250
        width: 255
        height: 44
        readOnly: true
    }
}
