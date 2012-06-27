var kMaxArraySize = 1;
var messageArray = new Array();
var eventModule = null;

function $(id) {
	return document.getElementById(id);
}

// Indicate success when the NaCl module has loaded.
function moduleDidLoad() {
	eventModule = document.getElementById('event_module');
	document.getElementById('eventString').innerHTML = "Module successfully loaded.";
}

function receiveMessage(message) {
	if (message.data.slice(0, 7) == "<table>") {
		document.getElementById('tableString').innerHTML = message.data;
	} else {
		messageArray.push(message.data);
		if (messageArray.length > kMaxArraySize) {
			messageArray.shift();
		}
		var newData = messageArray.join('<BR>');
		document.getElementById('eventString').innerHTML = newData;
		console.log(message.data);
	}
}

function getSettings() {
	var settings = "SET";
	
	settings += " numOfBuilds:" + document.getElementById('numOfBuilds').value;
	settings += " numOfGenerations:" + document.getElementById('numOfGenerations').value;
	settings += " ";
	
	console.log(settings);
	return settings;
}

function cancelQueue() {
	if (eventModule == null) {
		console.log('Module is not loaded.');
		document.getElementById('eventString').innerHTML = "Some stuff";
		return;
	}
	eventModule.postMessage('CANCEL');
}

function startBT() {
	if (eventModule == null) {
		console.log('Module is not loaded.');
		return;
	}
	eventModule.postMessage(getSettings());
//	eventModule.postMessage('START');
}