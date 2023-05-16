import "https://api.mapbox.com/mapbox-gl-js/v2.9.1/mapbox-gl.js";
const coordinates = [
[
      -117.90645057786406, 33.78608930228782
],
[
  -117.90625216632434, 33.785967812213556
],
[
  -117.90644528536663 ,33.785802848342634
]
]

  mapboxgl.accessToken = "pk.eyJ1IjoicGV0ZXJtZTEyMzQ1IiwiYSI6ImNsYjdvN25xYTBjeTEzb2t1eDVkMnhoMHEifQ.IHOzLIcI3IOLRwEVhGIEbw";
  const map = new mapboxgl.Map({
    container: "map",
    style: 'mapbox://styles/mapbox/streets-v11',
    center: [
      -117.90645057786406, 33.78608930228782
    ],
    zoom: 15
  });

  map.on('load', () => {
    map.addSource('route', {
    'type': 'geojson',
    'data': {
    'type': 'Feature',
    'properties': {},
    'geometry': {
    'type': 'LineString',
    'coordinates': coordinates
    }
    }
    });
    map.addLayer({
    'id': 'route',
    'type': 'line',
    'source': 'route',
    'layout': {
    'line-join': 'round',
    'line-cap': 'round'
    },
    'paint': {
    'line-color': '#888',
    'line-width': 8
    }
    });
    });
