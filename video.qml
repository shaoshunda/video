import QtQuick 2.0
import QtMultimedia 5.0

Rectangle {
    id:root
    color:"black"
    opacity: 0

    MediaPlayer {
        id:mediaPlayer
        objectName: qsTr("mediaPlayer")
        autoLoad: false

        onError: {
            if (MediaPlayer.NoError != error) {
                console.log("[qmlvideo] VideoItem.onError error " + error + " errorString " + errorString)
                root.fatalError()
            }
        }
    }

    VideoOutput {
        id: video
        objectName: qsTr("videoContent")
        anchors.fill: parent
        anchors.topMargin: 70
        source: mediaPlayer
    }
}

