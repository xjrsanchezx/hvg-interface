$( document ).ready(function() {

	// add all the elements
	for(var i=0; i<params.machines.length; i++) {
		$('<a>',{
			text: params.machines[i],			
			href: '#',
			click: function(){controller.elementActivated( $(this).text() );}
		}).appendTo("#machines");
		
		$('<br>').appendTo("#machines");	
	}
});
	