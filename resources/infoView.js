$( document ).ready(function() {
	// get the html with the info of the machine and append to the div element
	//document.write("file:///" + params.machineURL);
	
	if(params.machineURL == "")	// if the url is empty, jump to the next screen
		controller.elementActivated( 'forward' );
		
	$.get("file:///" + params.machineURL, function(data){		
		// change relative paths of the images to absolute path
		var absolutePath =  "file:///" + params.machineURL.substr( 0, params.machineURL.lastIndexOf("/")+1 );
		$("#machineInfo").html(data);
		
		$('img').each( function(){			
			$(this).attr('src', absolutePath + $(this).attr('src') );
		});
		
		
	});
	
	
	// click events
	$(".clickable").click( function() {
		controller.elementActivated( $(this).attr('id') );
	});
});