import QtQuick 2.3
import QtQuick.Controls 1.2

ApplicationWindow {
    id: p
    width: 400; height: 400
    color: "#00557f"
    title: qsTr("Многочлены")

    Button {
        id: p1
        x: 16
        y: 13
        width: 111
        height: 39
        text: qsTr("Сложение")
    }

    Button {
        id: p2
        x: 147
        y: 13
        width: 111
        height: 39
        text: qsTr("Вычитание")
    }

    Button {
        id: p3
        x: 276
        y: 13
        width: 111
        height: 39
        text: qsTr("Умножение на число")
    }

    Button {
        id: p4
        x: 16
        y: 58
        width: 111
        height: 39
        text: qsTr("Умножение на букву")
    }

    Button {
        id: p5
        x: 147
        y: 58
        width: 111
        height: 39
        text: qsTr("Старший
коэффициент")
    }

    Button {
        id: p6
        x: 276
        y: 58
        width: 111
        height: 39
        text: qsTr("Степень")
    }

    Button {
        id: p7
        x: 16
        y: 106
        width: 111
        height: 39
        text: qsTr("Вынесение НОК")
    }

    Button {
        id: p8
        x: 147
        y: 106
        width: 111
        height: 39
        text: qsTr("Умножение")
    }

    Button {
        id: p9
        x: 276
        y: 106
        width: 111
        height: 39
        text: qsTr("Частное")
    }

    Button {
        id: p10
        x: 16
        y: 154
        width: 111
        height: 39
        text: qsTr("Остаток")
    }

    Button {
        id: p11
        x: 147
        y: 154
        width: 111
        height: 39
        text: qsTr("НОД")
    }

    Button {
        id: p12
        x: 276
        y: 154
        width: 111
        height: 39
        text: qsTr("Производная")
    }

    Button {
        id: p13
        x: 16
        y: 202
        width: 111
        height: 39
        text: qsTr("Преобразование")
    }
}
