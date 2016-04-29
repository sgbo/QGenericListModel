import QtQuick 2.3
import QtQuick.Window 2.2

Window {
    visible: true
    width: 500
    height:300

    MouseArea {
        anchors.fill: parent
        onClicked: {
            Qt.quit();
        }
    }

    ListView {
        anchors.fill: parent

        model: listModel

        delegate: Text { text: model.name + " " + model.id }
    }
}

