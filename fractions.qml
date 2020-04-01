import QtQuick 2.3
import QtQuick.Controls 1.2

ApplicationWindow {
    id: f
    width: 400; height: 400
    color: "#00557f"
    title: qsTr("Дроби")

    Button {
        id: q1
        x: 16
        y: 13
        width: 111
        height: 39
        text: qsTr("Сокращение")
    }

    Button {
        id: q2
        x: 147
        y: 13
        width: 111
        height: 39
        text: qsTr("Проверка на целое")
    }

    Button {
        id: q3
        x: 276
        y: 13
        width: 111
        height: 39
        text: qsTr("Целое в дробное")
    }

    Button {
        id: q4
        x: 16
        y: 58
        width: 111
        height: 39
        text: qsTr("Дробное в целое")
    }

    Button {
        id: q5
        x: 147
        y: 58
        width: 111
        height: 39
        text: qsTr("Сложение")
    }

    Button {
        id: q6
        x: 276
        y: 58
        width: 111
        height: 39
        text: qsTr("Вычитание")
    }

    Button {
        id: q7
        x: 16
        y: 106
        width: 111
        height: 39
        text: qsTr("Умножение")
    }

    Button {
        id: q8
        x: 147
        y: 106
        width: 111
        height: 39
        text: qsTr("Деление")
    }
}
