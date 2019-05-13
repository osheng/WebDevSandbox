var time = new Date().getTime();
     $(document.body).bind("mousemove keypress", function(e) {
         time = new Date().getTime();
     });

     function refresh() {
         if(new Date().getTime() - time >= 1)
             window.location.reload(true);
         else
             setTimeout(refresh, 1);
     }

     setTimeout(refresh, 1);
