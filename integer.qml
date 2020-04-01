import QtQuick 2.3
import QtQuick.Controls 1.2

ApplicationWindow {
    id: i
    width: 400; height: 400
    color: "#00557f"
    title: qsTr("Целые числа")

    Button {
        id: z1
        x: 16
        y: 13
        width: 111
        height: 39
        text: qsTr("Абсолютная величина")
    }

    Button {
        id: z2
        x: 147
        y: 13
        width: 111
        height: 39
        text: qsTr("Проверка знака")
    }

    Button {
        id: z3
        x: 276
        y: 13
        width: 111
        height: 39
        text: qsTr("Умножение на (-1)")
    }

    Button {
        id: z4
        x: 16
        y: 58
        width: 111
        height: 39
        text: qsTr("Натуральное в целое")
    }

    Button {
        id: z5
        x: 147
        y: 58
        width: 111
        height: 39
        text: qsTr("Неотрицательное
в натуральное")
    }

    Button {
        id: z6
        x: 276
        y: 58
        width: 111
        height: 39
        text: qsTr("Сложение")
    }

    Button {
        id: z7
        x: 16
        y: 107
        width: 111
        height: 39
        text: qsTr("Вычитание")
    }

    Button {
        id: z8
        x: 147
        y: 107
        width: 111
        height: 39
        text: qsTr("Умножение")
    }

    Button {
        id: z9
        x: 276
        y: 107
        width: 111
        height: 39
        text: qsTr("Частное")
    }

    Button {
        id: z10
        x: 16
        y: 155
        width: 111
        height: 39
        text: qsTr("Остаток")
    }
}
