var isMobile = false; //initiate as false

window.addEventListener( "pageshow", function ( event ) {
    var historyTraversal = event.persisted || 
                           ( typeof window.performance != "undefined" && 
                                window.performance.navigation.type === 2 );
    if ( historyTraversal ) {
      $('.usa-form').trigger("reset");
    }
});

$(document).ready(function () {
 
  // Device detection
  if (
    /(android|bb\d+|meego).+mobile|avantgo|bada\/|blackberry|blazer|compal|elaine|fennec|hiptop|iemobile|ip(hone|od)|ipad|iris|kindle|Android|Silk|lge |maemo|midp|mmp|netfront|opera m(ob|in)i|palm( os)?|phone|p(ixi|re)\/|plucker|pocket|psp|series(4|6)0|symbian|treo|up\.(browser|link)|vodafone|wap|windows (ce|phone)|xda|xiino/i.test(
      navigator.userAgent
    ) ||
    /1207|6310|6590|3gso|4thp|50[1-6]i|770s|802s|a wa|abac|ac(er|oo|s\-)|ai(ko|rn)|al(av|ca|co)|amoi|an(ex|ny|yw)|aptu|ar(ch|go)|as(te|us)|attw|au(di|\-m|r |s )|avan|be(ck|ll|nq)|bi(lb|rd)|bl(ac|az)|br(e|v)w|bumb|bw\-(n|u)|c55\/|capi|ccwa|cdm\-|cell|chtm|cldc|cmd\-|co(mp|nd)|craw|da(it|ll|ng)|dbte|dc\-s|devi|dica|dmob|do(c|p)o|ds(12|\-d)|el(49|ai)|em(l2|ul)|er(ic|k0)|esl8|ez([4-7]0|os|wa|ze)|fetc|fly(\-|_)|g1 u|g560|gene|gf\-5|g\-mo|go(\.w|od)|gr(ad|un)|haie|hcit|hd\-(m|p|t)|hei\-|hi(pt|ta)|hp( i|ip)|hs\-c|ht(c(\-| |_|a|g|p|s|t)|tp)|hu(aw|tc)|i\-(20|go|ma)|i230|iac( |\-|\/)|ibro|idea|ig01|ikom|im1k|inno|ipaq|iris|ja(t|v)a|jbro|jemu|jigs|kddi|keji|kgt( |\/)|klon|kpt |kwc\-|kyo(c|k)|le(no|xi)|lg( g|\/(k|l|u)|50|54|\-[a-w])|libw|lynx|m1\-w|m3ga|m50\/|ma(te|ui|xo)|mc(01|21|ca)|m\-cr|me(rc|ri)|mi(o8|oa|ts)|mmef|mo(01|02|bi|de|do|t(\-| |o|v)|zz)|mt(50|p1|v )|mwbp|mywa|n10[0-2]|n20[2-3]|n30(0|2)|n50(0|2|5)|n7(0(0|1)|10)|ne((c|m)\-|on|tf|wf|wg|wt)|nok(6|i)|nzph|o2im|op(ti|wv)|oran|owg1|p800|pan(a|d|t)|pdxg|pg(13|\-([1-8]|c))|phil|pire|pl(ay|uc)|pn\-2|po(ck|rt|se)|prox|psio|pt\-g|qa\-a|qc(07|12|21|32|60|\-[2-7]|i\-)|qtek|r380|r600|raks|rim9|ro(ve|zo)|s55\/|sa(ge|ma|mm|ms|ny|va)|sc(01|h\-|oo|p\-)|sdk\/|se(c(\-|0|1)|47|mc|nd|ri)|sgh\-|shar|sie(\-|m)|sk\-0|sl(45|id)|sm(al|ar|b3|it|t5)|so(ft|ny)|sp(01|h\-|v\-|v )|sy(01|mb)|t2(18|50)|t6(00|10|18)|ta(gt|lk)|tcl\-|tdg\-|tel(i|m)|tim\-|t\-mo|to(pl|sh)|ts(70|m\-|m3|m5)|tx\-9|up(\.b|g1|si)|utst|v400|v750|veri|vi(rg|te)|vk(40|5[0-3]|\-v)|vm40|voda|vulc|vx(52|53|60|61|70|80|81|83|85|98)|w3c(\-| )|webc|whit|wi(g |nc|nw)|wmlb|wonu|x700|yas\-|your|zeto|zte\-/i.test(
      navigator.userAgent.substr(0, 4)
    )
  ) {
    isMobile = true;
    $(document.body).addClass("mobile");
  }

  /* Check if alert is present and add body class for blue body linear gradient/white hero overlay */
  if ($("#alert").is(":visible")) {
    $(document.body).addClass("alert-active");
  }

  /* Primary Links interaction */
  var currKey = null;
  $(document).keydown(function (event) {
    //currKey = event.code;//code doesn't work in IE
    currKey = event.which;
    //console.log("keydown() - currentKey = " + currKey);
    //console.log("keydown() - what is focused? " + $(":focus").text());

    // Workaround to allow use of Escape key, however it creates a bug where user then has to press the Enter or Spacebar key twice to re-open the nav
    // Ticket submitted and accepted by USWDS and in progress to add this feature - https://github.com/uswds/uswds/issues/3396
    // switch (currKey) {
    //   case "Enter":
    //   case 13:
    //   case "Space":
    //   case 32:
    //     //console.log("Enter/Space key clicked - find closed nav and open it");
    //     // $(this).find(".usa-nav__link").attr("aria-expanded", "true");
    //     // $(this).find(".usa-nav__submenu").removeAttr("hidden");
    //     $("button:focus").find(".usa-nav__link").attr("aria-expanded", "true");
    //     $("button:focus").find(".usa-nav__submenu").removeAttr("hidden");
    //     break;
    //   case 27:
    //     //console.log("Escape key clicked - find open nav and close it");
    //     //$(":focus").find(".usa-nav__link").attr("aria-expanded", "false");
    //     //$(":focus").find(".usa-nav__submenu").attr("hidden", "");
    //     $(".usa-nav__primary-item .usa-nav__link[aria-expanded=true]")
    //       .siblings()
    //       .attr("hidden", "");
    //     $(".usa-nav__primary-item .usa-nav__link[aria-expanded=true]").attr(
    //       "aria-expanded",
    //       "false"
    //     );
    //     break;
    // }
  });
  $(document).keyup(function (event) {
    setTimeout(function () {
      //console.log("keyup() - currentKey = " + currKey);
      currKey = null;
    }, 100);
  });
  $("body:not(.mobile) .usa-nav__primary-item:not(#search)").click(function (
    e
  ) {
    //console.log("CLICK FUNCTION > START - currentKey = " + currKey);
    if (currKey != null) {
      switch (currKey) {
        case "Enter":
        case 13:
        case "Space":
        case 32:
          // do nothing, allow accordion to open for accessibility
          break;
      }
    } else {
      // Click through to the "learn more" link URL within megamenu as the primary link for each main nav link on desktop and tablet */
      //console.log("CLICKING THROUGH - currentKey = " + currKey);
      window.location.href = $(this).find("article li a").attr("href");
    }
    currKey = null;
    //console.log("CLICK FUNCTION > END - currentKey = " + currKey);
  });

  /* Mega menu submenu expansion/collapse on hover - all except sticky nav search icon which is on click */
  let timeoutRef;
  let timerFlag = false;

  /* When mouse enters Nav menu item, it expands after .5 seconds */
  $("body:not(.mobile) .usa-nav__primary-item:not(#search)").mouseenter(
    function () {
      var $this = $(this);
      $("#search .usa-accordion__button").attr("aria-expanded", "false");
      $("#search .usa-nav__submenu").attr("hidden", "");

      if (timerFlag === false) {
        timeoutRef = setTimeout(function() {
          $($this).find(".usa-nav__link").attr("aria-expanded", "true");
          $($this).find(".usa-nav__submenu").removeAttr("hidden");
  
          $("#search .usa-accordion__button").attr("aria-expanded", "false");
          $("#search .usa-nav__submenu").attr("hidden", "");

          timerFlag = true;
        }, 500);
      }
    }
  );

  /* When mouse leaves Nav menu item, clears timeout and closes menu item */
  $("body:not(.mobile) .usa-nav__primary-item:not(#search)").mouseleave(
    function () {
      clearTimeout(timeoutRef);
      timerFlag = false; 
      $("body:not(.mobile) .usa-nav__link").attr("aria-expanded", "false");
      $("body:not(.mobile) .usa-nav__submenu").attr("hidden", "");
      $("#search .usa-accordion__button").attr("aria-expanded", "false");
      $("#search .usa-nav__submenu").attr("hidden", "");
      counter = 0;
    }
  );

   /* When tabbing leaves a nav menu item, exit nav menu */
   $("body").on("keyup", function(e) {
    if (e.which == 9) {
      let cssClasses = e.target.classList;
      let containsInsideNav = false; 
      
      /* Check to see if tabbed element contains class inside-nav */
      for (let i = 0; i < cssClasses.length; i++) {
        if (cssClasses[i] === 'inside-nav') {
          containsInsideNav = true; 
        }
      }

      if (containsInsideNav === false) {
        clearTimeout(timeoutRef);
        timerFlag = false; 
        $("body:not(.mobile) .usa-nav__link").attr("aria-expanded", "false");
        $("body:not(.mobile) .usa-nav__submenu").attr("hidden", "");
        $("#search .usa-accordion__button").attr("aria-expanded", "false");
        $("#search .usa-nav__submenu").attr("hidden", "");
        counter = 0;
      }
    }
  });

  /* Sticky nav search icon interaction - click to expand is default in USWDS */
  $("#search .usa-accordion__button").click(function (e) {
    noBubble(e);
    //console.log(
    //   $("#search .usa-accordion__button").attr("id") +
    //     " - " +
    //     $("#search .usa-accordion__button").attr("aria-expanded")
    // );

    // JavaScript version of above as a hack for IE
    if (counter % 2 == 0) {
      // console.log("even number");
      document
        .querySelector("#search .usa-accordion__button")
        .setAttribute("aria-expanded", "true");
      document
        .querySelector("#search .usa-nav__submenu")
        .removeAttribute("hidden");
    } else {
      // console.log("odd number");
      document
        .querySelector("#search .usa-accordion__button")
        .setAttribute("aria-expanded", "false");
      document
        .querySelector("#search .usa-nav__submenu")
        .setAttribute("hidden", "");
    }
    counter++;
  });

  /* Init functions */
  /* Responsive Tabs */
  RESPONSIVEUI.responsiveTabs();

  /* Check scroll position onload */
  isIE();
  $(window).scroll();
}); /* end document ready function */

var counter = 0;

function noBubble(e) {
  e = e || event;
  if (e) {
    e.returnValue = false;
    e.cancelBubble = true;
    e.stopPropagation();
    e.preventDefault();
  }
  event.preventDefault();
  event.defaultPrevented; // true
}

/* Sample function that returns boolean in case the browser is Internet Explorer*/
function isIE() {
  ua = navigator.userAgent;
  /* MSIE used to detect old browsers and Trident used to newer ones*/
  var is_ie = ua.indexOf("MSIE ") > -1 || ua.indexOf("Trident/") > -1;

  return is_ie;
}
/* Create an alert to show if the browser is IE or not */
if (isIE()) {
  // Internet Explorer
} else {
  // NOT Internet Explorer
  $("body:not(.mobile) .usa-nav__submenu").addClass("animated fadeIn");
}

/* Add sticky-active class when scrolled down on desktop to show/hide the search icon */
$(window).scroll(function () {

  if ($(this).scrollTop() > 0) {
    
    $(document.body).addClass("sticky-active");
    $("#search").css("pointer-events", "auto");

    document
      .querySelector("#search .usa-accordion__button")
      .setAttribute("tabindex", "0");
    document
      .querySelector("#search .usa-nav__submenu")
      .setAttribute("tabindex", "0");

  } else {

    document
      .querySelector("#search .usa-accordion__button")
      .setAttribute("aria-expanded", "false");
    document
      .querySelector("#search .usa-accordion__button")
      .setAttribute("tabindex", "-1");

    document
      .querySelector("#search .usa-nav__submenu")
      .setAttribute("hidden", "");
    document
      .querySelector("#search .usa-nav__submenu")
      .setAttribute("tabindex", "-1");
    
    $("#search").css("pointer-events", "none");

    counter = 0;

    $(document.body).removeClass("sticky-active");
  }
});
