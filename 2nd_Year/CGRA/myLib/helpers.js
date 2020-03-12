function hexToRgbA(hex) {
    var match = hex.match(/^#([A-Fa-f0-9][A-Fa-f0-9])([A-Fa-f0-9][A-Fa-f0-9])([A-Fa-f0-9][A-Fa-f0-9])$/);
    if (match)
        return [parseInt(match[1], 16)/255.0, parseInt(match[2], 16)/255.0, parseInt(match[3], 16)/255.0, 1.0];
    else
        return [hex[0]/255.0, hex[1]/255.0, hex[2]/255.0, 1.0];
}
