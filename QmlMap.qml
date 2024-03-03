import QtQuick 2.15
import QtLocation 6.6
import QtPositioning 6.6

Rectangle {
    id:window

    property double latitude: 49.29019
    property double longitude: 16.57822

    property Component locationmarker: locmarker

    Plugin {
        id:googlemapview
        name:"osm"

        PluginParameter{
            name: "osm.mapping.providersrepository.address"
            value: "http://maps-redirect.qt.io/osm/6.6/street-hires"
        }

        PluginParameter{
            name: "osm.mapping.highdpi_tiles"
            value: true
        }
    }

    MapView {
        id:mapview
        anchors.fill: parent
        map.plugin: googlemapview
        map.center: QtPositioning.coordinate(latitude, longitude)
        map.zoomLevel: 12
    }

    function setCenterPosition(lati, longi) {
        mapview.pan(latitude - lati, longitude - longi)
        latitude = lati
        longitude = longi
    }

    function setLocationMarking(lati, longi) {
        var item = locationmarker.createObject(window, {
                                                coordinate:QtPositioning.coordinate(lati, longi)
                                               })
        mapview.addMapItem(item)
    }

    Component {
        id:locmarker
        MapQuickItem {
            id:markerimg
            anchorPoint.x:image.width/2
            anchorPoint.y:image.height
            coordinate: QtPositioning.coordinate(latitude, longitude)
            sourceItem: Image {
                id: image
                width: 20
                height: 20
                source: "qrc:/firehouse.png"
            }

        }
    }
}
