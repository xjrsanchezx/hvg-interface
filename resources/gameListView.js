$( document ).ready(function() {
	
	// add all the elements
	for(var i=0; i<params.getNumGames(); i++) {
		$('<a>',{
			text: params.getGameName(i),			
			href: '#',
			click: function(){controller.elementActivated( $(this).text() );}
		}).appendTo("#games");
		
		$('<br>').appendTo("#games");	
	}
	
	// click events
	$(".clickable").click( function() {
		controller.elementActivated( $(this).attr('id') );
	});
});
	