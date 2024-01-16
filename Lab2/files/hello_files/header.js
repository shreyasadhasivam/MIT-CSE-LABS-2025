function syncSearch () {

    $("#query2").keyup(function(){
        $("#query3").val($("#query2").val());
    });

    $("#query3").keyup(function(){
        $("#query2").val($("#query3").val());
    });
    
}