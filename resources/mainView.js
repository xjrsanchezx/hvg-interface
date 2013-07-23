$( document ).ready(function() {

	for(var i=0; i<params.machines.length; i++) {
		$('<a>',{
			text: params.machines[i],			
			href: '#',
			click: function(){emit();}
		}).appendTo("#machines");
		
		$('<br>').appendTo("#machines");	
	}
});
	
	
	
	function emit()	{
		controller.elementActivated('hola');
	}